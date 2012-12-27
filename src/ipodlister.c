#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

#include "gpod-1.0/gpod/itdb.h"

// path to songs count
static const char *songs_count_path = "/songs_count";

// mount point of the ipod
static const char *ipod_mount_point = "/media/disk";

/**
 *
 * @return number of all songs
 */
int get_songs_count() {
  GError *error=NULL;
  Itdb_iTunesDB *itdb;

  int songscount = 0;
  itdb = itdb_parse(ipod_mount_point, &error);
  if (error)
  {
      if (error->message) {
	  g_print("%s\n", error->message);
      }
      g_error_free (error);
      error = NULL;
  }
  if(itdb) {
    songscount = itdb_tracks_number(itdb);
  }

  itdb_free(itdb);

  return songscount;
}

// simple, not-for-production int->string converter
char* convert_from_int(char *str, int n) {
  int LEN=15;
  snprintf(str, LEN, "%d", n);
  return str;
}

static int ipod_getattr(const char *path, struct stat *stbuf)
{
    int res = 0;
    char str[15];

    memset(stbuf, 0, sizeof(struct stat));
    if(strcmp(path, "/") == 0) {
        stbuf->st_mode = S_IFDIR | 0755;
        stbuf->st_nlink = 2;
    }
    else if(strcmp(path, songs_count_path) == 0) { // handle '/songs_count' file
        stbuf->st_mode = S_IFREG | 0444;
        stbuf->st_nlink = 1;
        stbuf->st_size = strlen(convert_from_int(str, get_songs_count()));
    }
    else
        res = -ENOENT;

    return res;
}

static int ipod_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
                         off_t offset, struct fuse_file_info *fi)
{
    (void) offset;
    (void) fi;

    if(strcmp(path, "/") != 0)
        return -ENOENT;

    filler(buf, ".", NULL, 0);
    filler(buf, "..", NULL, 0);
    filler(buf, songs_count_path + 1, NULL, 0);

    return 0;
}

static int ipod_open(const char *path, struct fuse_file_info *fi)
{
    if(strcmp(path, songs_count_path) != 0)
        return -ENOENT;

    if((fi->flags & 3) != O_RDONLY)
        return -EACCES;

    return 0;
}

static int ipod_read(const char *path, char *buf, size_t size, off_t offset,
                      struct fuse_file_info *fi)
{
    size_t len;
    (void) fi;
    char str[15];

    if(strcmp(path, songs_count_path) != 0)
        return -ENOENT;

    convert_from_int(str, get_songs_count());
    len = strlen(str);
    if (offset < len) {
        if (offset + size > len)
            size = len - offset;
        memcpy(buf, str + offset, size);
    } else
        size = 0;

    return size;
}


// structure that maps operations to the functions that provide them
static struct fuse_operations ipod_oper = {
    .getattr	= ipod_getattr,
    .readdir	= ipod_readdir,
    .open	= ipod_open,
    .read	= ipod_read,
};


int main(int argc, char *argv[])
{
  return fuse_main(argc, argv, &ipod_oper, NULL);
}
