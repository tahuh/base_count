#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "kseq.h"

KSEQ_INIT(gzFile, gzread)

int main(int argc, char **argv)
{
   if(argc < 2) {
       fprintf(stderr, "baseCounter_SE read1.fastq.gz\n");
       exit(-1);
   }
   char *fastq_name = argv[1];
	gzFile fp = gzopen(fastq_name, "r");
	kseq_t *seq = kseq_init(fp);
	int l = 0;
	unsigned long long bases = 0;
	fprintf(stderr, "[base_cnt] processing %s\n", fastq_name);
	while((l= kseq_read(seq)) >= 0){
		bases += seq->seq.l;
	}
	kseq_destroy(seq);
	gzclose(fp);
	fprintf(stdout, "%s\t%llu\n", fastq_name, bases);
}
