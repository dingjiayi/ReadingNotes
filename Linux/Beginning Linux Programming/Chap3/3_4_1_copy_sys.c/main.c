//
//  main.c
//  3_4_1_copy_sys.c
//
//  Created by 刘君义 on 16/11/28.
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
    const char *out = "/Users/dingjiayi/Practice/Chap3_test_copy_sys.txt";
    char ch;
    int rd, wr;
    
    rd = open(in, O_RDONLY);
    wr = open(out, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    
    while (read(rd, &ch, 1) == 1) {
        write(wr, &ch, 1);
    }
    
    return 0;
}
