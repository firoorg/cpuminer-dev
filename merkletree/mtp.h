//
//

#ifndef ZCOIN_MTP_H
#define ZCOIN_MTP_H

#endif //ZCOIN_MTP_H



#include "merkle-tree.hpp"

#include <immintrin.h>
#include "argon2ref/core.h"
#include "argon2ref/argon2.h"
#include "argon2ref/thread.h"
#include "argon2ref/blake2.h"
#include "argon2ref/blake2-impl.h"
#include "argon2ref/blamka-round-opt.h"
//#include "merkletree/sha.h"

//#include "openssl\sha.h"

#include "uint256.h"
//#include "serialize.h"
class CBlock;

/* Size of MTP proof */
const unsigned int MTP_PROOF_SIZE = 1471;// 1431;
/* Size of MTP block proof size */
const unsigned int MTP_BLOCK_PROOF_SIZE = 64;
/* Size of MTP block */
const unsigned int MTP_BLOCK_SIZE = 140;

typedef struct block_with_offset_ {
	block memory;
	//	char* proof;
	char proof[MTP_PROOF_SIZE];
} block_with_offset;

typedef struct block_mtpProof_ {
	block memory;
	char proof[MTP_PROOF_SIZE];
} block_mtpProof;

typedef struct mtp_Proof_ {
	char proof[MTP_PROOF_SIZE]; 
} mtp_Proof;



void mtp_hash(char* output, const char* input, unsigned int d, uint32_t TheNonce);
argon2_context init_argon2d_param(const char* input);
void getblockindex(uint32_t ij, argon2_instance_t *instance, uint32_t *out_ij_prev, uint32_t *out_computed_ref_block);


int mtp_solver(uint32_t TheNonce, argon2_instance_t *instance,
	uint64_t nBlockMTP[MTP_BLOCK_PROOF_SIZE*2][128], unsigned char *nProofMTP, unsigned char* resultMerkleRoot, unsigned char* mtpHashValue,
	MerkleTree TheTree, uint32_t* input, uint256 hashTarget);

int mtp_solver_nowriting(uint32_t TheNonce, argon2_instance_t *instance,
	unsigned char* resultMerkleRoot, uint32_t* input, uint256 hashTarget);

// MerkleTree::Elements mtp_init(argon2_instance_t *instance);
void mtp_init(argon2_instance_t *instance, MerkleTree::Elements  *elements);