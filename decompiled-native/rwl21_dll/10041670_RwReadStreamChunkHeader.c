// 10041670 RwReadStreamChunkHeader [Global]
// programa: RWL21.DLL

uint RwReadStreamChunkHeader(int *param_1)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint *puVar3;
  int iVar4;
  uint local_4;
  
                    /* 0x41670  325  RwReadStreamChunkHeader */
  iVar4 = 1;
  bVar2 = RwReadStream(param_1,&local_4,4);
  puVar3 = &local_4;
  do {
    uVar1 = *puVar3;
    iVar4 = iVar4 + -1;
    *puVar3 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
    puVar3 = puVar3 + 1;
  } while (iVar4 != 0);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    return local_4;
  }
  return 0;
}


