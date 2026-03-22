# Sqlite

Project Structure:

CORE:
Interface ->
SQL Command Processor -> (COMPILER) ->
Virtual Machine -> (BACKEND)

COMPILER:
Tokniser ->
Parser ->
Code Generator

BACKEND:
B-Tree ->
Pager ->
OS Interface

Overview:
In a database, a query goes through a chain of processing in order to retrieve or modify data.

A database utilizes a specialized database language (SQL) for which we need a compiler. The compiler of the language forms the frontend of the database project. The compiler outputs sqlite virtual machine bytecode.

The backend of the project runs on virtual machine that can execute sqlite bytecode outputted by the compiler. The backend consists of B-trees which stores tables or indices, the pager which receives commands to read/write data, and the os interface which interacts with the OS. 

Each B-tree is built from many nodes each one page in length. Using the B-tree, we can retrieve a page from the disk or save ti back to the disk.

The pager is like the backend controller. It is responsible for managing the correct offsets for reading/writing. It also maintains a cache of recently-accessed pages in memory and determines when those pages need to be written back.

The OS interface allows the backend to interact with the system's OS, and in turn the hardware. This is essential for making a persistent database where data is saved on persistent drives.