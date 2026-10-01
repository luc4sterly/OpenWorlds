// 10039c80 RwReadStreamChunkType [Global]
// program: RWL21.DLL

undefined4 RwReadStreamChunkType(int *param_1,uint *param_2)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  
                    /* 0x39c80  326  RwReadStreamChunkType */
  bVar2 = RwReadStream(param_1,param_2,4);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    uVar1 = *param_2;
    *param_2 = (uVar1 & 0xff00 | uVar1 << 0x10) << 8 | (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8;
    return 1;
  }
  return 0;
}


