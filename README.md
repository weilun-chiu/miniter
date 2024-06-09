# MINITER - SimpleList with Iterator Demo

This repository contains a simple implementation of a singly linked list in C++ (`SimpleList`) that holds data as `void*` pointers. The primary goal is to demonstrate how to implement an iterator that supports range-based for loops with minimal effort.

## Overview

The `SimpleList` class is a basic singly linked list with the following features:
- Insertion at the back of the list.
- An iterator that allows the list to be used in range-based for loops.

## Features

- **Node Structure**: Defines a `Node` that holds `void*` data and a pointer to the next node.
- **SimpleList Class**:
  - `insertAtBack(void* data)`: Adds a new node with the given data at the end of the list.
  - `begin()`: Returns an iterator to the first node.
  - `end()`: Returns an iterator to the position past the last node (nullptr).
- **Iterator Class**:
  - Supports `operator*()`, `operator++()`, and `operator!=()` to enable range-based for loops.
