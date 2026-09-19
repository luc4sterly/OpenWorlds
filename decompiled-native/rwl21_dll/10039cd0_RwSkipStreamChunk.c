// 10039cd0 RwSkipStreamChunk [Global]
// programa: RWL21.DLL

undefined4 RwSkipStreamChunk(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint local_4;
  
                    /* 0x39cd0  492  RwSkipStreamChunk */
  bVar1 = RwReadStream(param_1,&local_4,4);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    local_4 = (local_4 & 0xff00 | local_4 << 0x10) << 8 |
              (local_4 & 0xff0000 | local_4 >> 0x10) >> 8;
    if (local_4 == 0) {
      return 1;
    }
    iVar2 = RwSeekStream(param_1,local_4);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}


