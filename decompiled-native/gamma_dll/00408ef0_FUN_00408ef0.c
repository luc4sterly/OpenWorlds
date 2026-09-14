// 00408ef0 FUN_00408ef0 [Global]
// programa: gamma.dll

int __thiscall FUN_00408ef0(void *this,char param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar1 = **(uint **)this;
  if (uVar1 <= param_2) {
    return -1;
  }
  uVar2 = (*(uint **)this)[3];
  pcVar3 = (char *)(param_2 + uVar2);
  while( true ) {
    if ((char *)(uVar1 + uVar2) <= pcVar3) {
      return -1;
    }
    if (param_1 == *pcVar3) break;
    pcVar3 = pcVar3 + 1;
  }
  return (int)pcVar3 - uVar2;
}


