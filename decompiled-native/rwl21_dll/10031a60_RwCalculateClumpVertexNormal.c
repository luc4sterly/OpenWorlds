// 10031a60 RwCalculateClumpVertexNormal [Global]
// programa: RWL21.DLL

int RwCalculateClumpVertexNormal(int param_1,int param_2)

{
  int iVar1;
  
                    /* 0x31a60  23  RwCalculateClumpVertexNormal */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((0 < param_2) && (param_2 < *(int *)(*(int *)(param_1 + 0x88) + 8) + -7)) {
    iVar1 = FUN_10041c90(*(int *)(param_1 + 0x88),param_2);
    *(byte *)(iVar1 + 0x48) = *(byte *)(iVar1 + 0x48) & 0xbf;
    iVar1 = FUN_10041c90(*(int *)(param_1 + 0x88),param_2);
    FUN_10041df0(iVar1);
    *(undefined4 *)(param_1 + 0xc0) = 0;
    return param_1;
  }
  FUN_1000cba0(0x19);
  return 0;
}


