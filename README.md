# base_count
Counting NGS read bases

## Requirements
- zlib
- gcc
- OS tested CentOS6, Ubuntu 14.04, 16.04,18.0

## Compile
```
$ gcc -O3 -Wall -o baseCounter_SE base_count_se.c -lz # For single end reads
$ gcc -O3 -Wall -o baseCounter_PE base_count_pe.c -lz # For paired end reads
```

## License
MIT
