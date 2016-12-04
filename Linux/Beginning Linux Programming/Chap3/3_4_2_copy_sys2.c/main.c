//
//  main.c
//  3_4_2_copy_sys2.c
//
//  Created by 刘君义 on 16/12/4.
//  Copyright © 2016年 刘君义. All rights reserved.
//

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, const char * argv[]) {
    // insert code here...
    const char *in = "/Users/dingjiayi/Practice/Chap3_test.txt";
    const char *out = "/Users/dingjiayi/Practice/Chap3_test_cp2.txt";
    
    char block[128];
    
    int rd = open(in, O_RDONLY);
    int wr = open(out, O_WRONLY);
    
    while((read(rd, block, 128)) == 128){
        write(wr, block, 128);
    }
    
    return 0;
}
