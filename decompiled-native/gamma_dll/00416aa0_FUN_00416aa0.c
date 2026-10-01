// 00416aa0 FUN_00416aa0 [Global]
// program: gamma.dll

void __thiscall FUN_00416aa0(void *this,char *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = -1;
  pcVar2 = param_1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = (char *)FUN_00450b60(0xffffffff - iVar3);
  FUN_0044d6b0(pcVar2,param_1);
  FUN_00416940(this,pcVar2,10,0,0,0);
  return;
}


