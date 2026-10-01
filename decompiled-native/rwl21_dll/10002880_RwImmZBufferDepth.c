// 10002880 RwImmZBufferDepth [Global]
// program: RWL21.DLL

int RwImmZBufferDepth(int param_1)

{
  longlong lVar1;
  
                    /* 0x2880  277  RwImmZBufferDepth */
  if (*(int *)(param_1 + 0x218) == 1) {
    lVar1 = __ftol();
    return (int)lVar1 + 0x1000000;
  }
  lVar1 = __ftol();
  return (int)lVar1 + 0x1000000;
}


