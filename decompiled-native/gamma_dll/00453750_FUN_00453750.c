// 00453750 FUN_00453750 [Global]
// programa: gamma.dll

int __thiscall FUN_00453750(void *this,char param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = **(int **)this;
  if (iVar1 == 0) {
    return -1;
  }
  uVar2 = iVar1 - 1;
  if (uVar2 < param_2) {
    param_2 = uVar2;
  }
  iVar1 = (*(int **)this)[3];
  iVar3 = param_2 + 1 + iVar1;
  while( true ) {
    if (iVar3 == iVar1) {
      return -1;
    }
    if (*(char *)(iVar3 + -1) != param_1) break;
    iVar3 = iVar3 + -1;
  }
  return (iVar3 - iVar1) + -1;
}


