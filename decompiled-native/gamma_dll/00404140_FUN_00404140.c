// 00404140 FUN_00404140 [Global]
// programa: gamma.dll

int * __thiscall FUN_00404140(void *this,LPCSTR param_1,LPCSTR param_2,int param_3)

{
  UINT UVar1;
  HSZ pHVar2;
  HCONV pHVar3;
  
  *(int *)((int)this + 0xc) = param_3;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  if ((DAT_0049fa0c == 0) && (DAT_004a0430 == 0)) {
    DAT_0049fa0c = 1;
    UVar1 = DdeInitializeA(&DAT_004a0430,(PFNCALLBACK)&LAB_004040f0,0x10,0);
    if (UVar1 != 0) {
      DAT_004a0430 = 0;
    }
  }
  if (DAT_004a0430 != 0) {
    pHVar2 = DdeCreateStringHandleA(DAT_004a0430,param_1,0x3ec);
    *(HSZ *)((int)this + 4) = pHVar2;
    if (*(int *)((int)this + 4) == 0) {
      return this;
    }
    pHVar2 = DdeCreateStringHandleA(DAT_004a0430,param_2,0x3ec);
    *(HSZ *)((int)this + 8) = pHVar2;
    if (*(HSZ *)((int)this + 8) == (HSZ)0x0) {
      DdeFreeStringHandle(DAT_004a0430,*(HSZ *)((int)this + 4));
      return this;
    }
    pHVar3 = DdeConnect(DAT_004a0430,*(HSZ *)((int)this + 4),*(HSZ *)((int)this + 8),
                        (PCONVCONTEXT)0x0);
    *(HCONV *)this = pHVar3;
    if (*(int *)this == 0) {
      DdeFreeStringHandle(DAT_004a0430,*(HSZ *)((int)this + 4));
      DdeFreeStringHandle(DAT_004a0430,*(HSZ *)((int)this + 8));
      return this;
    }
    if (DAT_0049fcc0 == (void *)0x0) {
      DAT_0049fcc0 = this;
    }
    if (DAT_0049fcb8 != (void *)0x0) {
      *(void **)((int)DAT_0049fcb8 + 0x14) = this;
    }
    DAT_0049fcb8 = this;
    *(undefined4 *)((int)this + 0x10) = 1;
  }
  return this;
}


