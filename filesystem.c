#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "filesystem.h"
#include "softwaredisk.h"

#define MAX_FILES                   512                       
#define DATA_BITMAP_BLOCK           0       // max SOFTWARE_DISK_BLOCK_SIZE*8 bits
#define INODE_BITMAP_BLOCK          1       // max SOFTWARE_DISK_BLOCK_SIZE*8 bits
#define FIRST_INODE_BLOCK           2
#define LAST_INODE_BLOCK            5       // 128 inodes per blocks,
                                            // max of 4*128 = 512 inodes, thus 512 files
#define INODES_PER_BLOCK            128     
#define FIRST_DIR_ENTRY_BLOCK       6
#define LAST_DIR_ENTRY_BLOCK        69
#define DIR_ENTRIES_PER_BLOCK       8       // 8 DE per block          
                                            // max 0f 64*8 = 512 Directory entries corresponding to max file for single-level directory structure
#define FIRST_DATA_BLOCK            70  
#define LAST_DATA_BLOCK             4095
#define MAX_FILENAME_SIZE           507
#define NUM_DIRECT_INODE_BLOCKS     13
#define NUM_SINGLE_INDIRECT_BLOCKS  (SOFTWARE_DISK_BLOCK_SIZE / sizeof(uint16_t))

#define MAX_FILE_SIZE   (NUM_DIRECT_INODE_BLOCKS + NUM_SINGLE_INDIRECT_BLOCKS) * SOFTWARE_DISK_BLOCK_SIZE
#define MAX_FILE_NAME_LENGTH        256
#define BIT_VECTOR_LENGTH           (SOFTWARE_DISK_BLOCK_SIZE/sizeof(uint64_t))

typedef struct DirEntry{
    char fsname[MAX_FILE_NAME_LENGTH];
    uint16_t num_inode;
    // 
} DirEntry;

typedef struct inode {
    uint64_t size;
    uint16_t undirect[NUM_DIRECT_INODE_BLOCKS];
    uint16_t indirect;
} inode;

// internals of software disk implementation
typedef struct FileSystemInternals {
  struct DirEntry direntry;
  struct inode i_data;
  FileMode mode;
  uint64_t position;
} FileSystemInternals;

struct FileSystemInternals *file; 
FSError fserror;


// function prototypes for filesystem API
int set_block(){
    uint64_t bit_vec[BIT_VECTOR_LENGTH];
    read_sd_block(bit_vec, 0);
    uint64_t full = 0xFFFFFFFFFFFFFFFF;
    int pos = 0;

    for (int i = 0; i < BIT_VECTOR_LENGTH){
        // Check if the bit vector is full
        if(!(bit_vec[i]^full)) pos += sizeof(uint64_t) * 
    }


}

File open_file(char *name, FileMode mode){
    fserror = FS_NONE;
    // check if filename has illegal character
    if (!fs.fp){
        fserror = FS_FILE_NOT_FOUND;
        return 0;
    }
    else{
        
    }
    //set current file position to byte 
}

File create_file(char *name){
    
}

void close_file(File file){

}

unsigned long read_file(File file, void *buf, unsigned long numbytes){

}

unsigned long write_file(File file, void *buf, unsigned long numbytes){

}

int seek_file(File file, unsigned long bytepos){
    if (! file) return 0;
    else{

    }
    
}

unsigned long file_length(File file){

}

int delete_file(char *name){

}

int file_exists(char *name){
    if (  )
}

void fs_print_error(void){
    switch(fserror) {
    case FS_NONE:
        printf("FS: No error. \n");
        break;
    case FS_OUT_OF_SPACE:
        printf("FS: Operation caused the software disk to fill up. \n");
        break;
    case FS_FILE_NOT_OPEN:
        printf("FS: File is not open. \n");
        break;
    case FS_FILE_OPEN:
        printf("FS: File is already open. Concurrent opens are not supported and neither is deleting a file that is open. \n");
        break;
    case FS_FILE_NOT_FOUND: 
        printf("FS: attempted open or delete of file that doesn't exist.\n");
        break;
    case FS_FILE_READ_ONLY: 
        printf("FS: attempted write to file opened for READ_ONLY. \n");
        break;
    case FS_FILE_ALREADY_EXISTS: 
        printf("FS: attemped creation of file with existing name. \n");
        break;
    case FS_EXCEEDS_MAX_FILE_SIZE: 
        printf("FS: seek or write would exceed max file size. \n");
        break;
    case FS_ILLEGAL_FILENAME: 
        printf("FS: filename begins with a null character. \n");
        break;
    case FS_IO_ERROR: 
        printf("FS: something really bad happened. \n");
        break;
    default:
    printf("FS: Unknown error code %d.\n", fserror);
    }
}

int check_structure_alignment(void){

}

// filesystem error code set (set by each filesystem function)
extern FSError fserror;






