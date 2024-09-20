### Basic Steps to Use `script`:
1. **Start the `script` session:** Run the following command to start recording terminal output to a file (e.g., output.txt):
`script output.txt`
2. **Run the program.**
3. **Stop the `script` session:** After the program finishes running, type `exit` or press `CTRL-D`.
### Optional Flags:
- **`-a` (append mode):** To add the output to an existing file rather than overwrite.
`script -a output.txt`
- By default, the output will be saved to a file names `typescript`.