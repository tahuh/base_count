#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "kseq.h"

KSEQ_INIT(gzFile, gzread)

int main(int argc, char **argv)
{
	if(argc < 3){
		fprintf(stdout, "usage : baseCounter_PE read1.fq read2.fq\n");
		return -1;
	}
	gzFile fq1 = NULL;
	gzFile fq2 = NULL;
	kseq_t *seq1 = NULL;
	kseq_t *seq2 = NULL;
	int l1 = 0;
	int l2 = 0;
	unsigned long long bases = 0;
	fq1 = gzopen(argv[1], "r");
	if(!fq1){
		fprintf(stderr, "Failed to open read1 %s\n", argv[1]);
		return -1;
	}
	fq2 = gzopen(argv[2], "r");
	if(!fq2){
		gzclose(fq1);
		fprintf(stderr, "Failed to open read2 %s\n", argv[2]);
	}
	seq1 = kseq_init(fq1);
	seq2 = kseq_init(fq2);
	while( ((l1=kseq_read(seq1)) >= 0) && ( (l2 = kseq_read(seq2)) >= 0) ) {
		bases += seq1->seq.l;
		bases += seq2->seq.l;
	}
	fprintf(stdout, "%llu\n", bases);
	kseq_destroy(seq1); kseq_destroy(seq2);
	gzclose(fq1); gzclose(fq2);
	return 0;
}
