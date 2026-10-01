// 00408b30 FUN_00408b30 [Global]
// program: gamma.dll

int __thiscall FUN_00408b30(void *this,char param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  
  iVar1 = **(int **)this;
  if (iVar1 == 0) {
    return -1;
  }
  uVar3 = iVar1 - 1;
  if (uVar3 < param_2) {
    param_2 = uVar3;
  }
  pcVar2 = (char *)(*(int **)this)[3];
  pcVar4 = pcVar2 + param_2;
  while( true ) {
    if (param_1 == *pcVar4) {
      return (int)pcVar4 - (int)pcVar2;
    }
    if (pcVar4 <= pcVar2) break;
    pcVar4 = pcVar4 + -1;
  }
  return -1;
}


