// 100027a0 RwImmVertexPixelSpace [Global]
// programa: RWL21.DLL

void RwImmVertexPixelSpace(int param_1)

{
  longlong lVar1;
  
                    /* 0x27a0  276  RwImmVertexPixelSpace */
  if (((*(byte *)(param_1 + 0x48) & 0x3f) != 0) && ((*(uint *)(param_1 + 0x14) & 0x7fffffff) != 0))
  {
    if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
      lVar1 = __ftol();
      *(int *)(param_1 + 0x18) = (int)lVar1;
      lVar1 = __ftol();
      *(int *)(param_1 + 0x1c) = (int)lVar1;
      lVar1 = __ftol();
      *(int *)(param_1 + 0x20) = (int)lVar1 + 0x1000000;
      return;
    }
    lVar1 = __ftol();
    *(int *)(param_1 + 0x18) = (int)lVar1;
    lVar1 = __ftol();
    *(int *)(param_1 + 0x1c) = (int)lVar1;
    lVar1 = __ftol();
    *(int *)(param_1 + 0x20) = (int)lVar1 + 0x1000000;
  }
  return;
}


