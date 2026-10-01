// 0044b140 FUN_0044b140 [Global]
// program: gamma.dll

int __thiscall FUN_0044b140(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)this;
  while( true ) {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(iVar1 + 8);
    }
    if (iVar2 == param_1) break;
    iVar2 = *(int *)this;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
    }
  }
  return iVar1;
}


