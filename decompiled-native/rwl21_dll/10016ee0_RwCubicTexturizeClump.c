// 10016ee0 RwCubicTexturizeClump [Global]
// program: RWL21.DLL

int RwCubicTexturizeClump(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  
                    /* 0x16ee0  52  RwCubicTexturizeClump */
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x88);
    iVar2 = 8;
    if (8 < *(int *)(iVar1 + 8)) {
      iVar3 = iVar1 + 0x3f8;
      do {
        iVar2 = iVar2 + 1;
        lVar4 = __ftol();
        *(uint *)(iVar3 + 0x1c) = (int)lVar4 + 0x8000U & 0xffff;
        lVar4 = __ftol();
        *(uint *)(iVar3 + 0x18) = (int)lVar4 + 0x8000U & 0xffff;
        *(byte *)(iVar3 + -4) = *(byte *)(iVar3 + -4) | 0x80;
        iVar3 = iVar3 + 0x74;
      } while (iVar2 < *(int *)(iVar1 + 8));
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


