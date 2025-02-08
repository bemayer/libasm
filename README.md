# libasm

## Overview

**libasm** is a library implemented in Assembly language, providing a collection of fundamental functions commonly used in the standard C library. This project serves as an exercise in low-level programming, focusing on performance optimization and a deeper understanding of system-level operations.

## Features

The library includes the following functions, which are part of the standard C library:

- **ft_strlen**: Computes the length of a string.
- **ft_strcpy**: Copies a string from source to destination.
- **ft_strcmp**: Compares two strings lexicographically.
- **ft_strdup**: Duplicates a string by allocating sufficient memory and copying the content.
- **ft_read**: Reads data from a file descriptor into a buffer.
- **ft_write**: Writes data from a buffer to a file descriptor.
- **ft_atoi_base**: Converts a string representing a number in a specified base to an integer.
- **ft_list_push_front**: Adds a new element at the beginning of a linked list.
- **ft_list_size**: Returns the number of elements in a linked list.
- **ft_list_sort**: Sorts the elements of a linked list.
- **ft_list_remove_if**: Removes elements from a linked list that match a specified condition.

## Files

The repository contains the following files:

- **Makefile**: Automates the build process of the library.
- **main.c**: A test program written in C to demonstrate and validate the functions provided by the library.
- Assembly source files for each function:
  - ft_strlen.s
  - ft_strcpy.s
  - ft_strcmp.s
  - ft_strdup.s
  - ft_read.s
  - ft_write.s
  - ft_atoi_base.s
  - ft_list_push_front.s
  - ft_list_size.s
  - ft_list_sort.s
  - ft_list_remove_if.s

## Usage

To build the library and run the test program:

1. Clone the repository
   ```bash
   git clone https://github.com/bemayer/libasm.git  
   cd libasm
   ```

3. Compile the library:
   ```bash
   make
   ```

4. Compile and run the test program:
   ```bash
   gcc -o test main.c libasm.a
   ./test
   ```
