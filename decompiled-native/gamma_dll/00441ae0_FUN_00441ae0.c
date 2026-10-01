// 00441ae0 FUN_00441ae0 [Global]
// program: gamma.dll

undefined4
FUN_00441ae0(undefined4 param_1,char *param_2,undefined4 *param_3,int param_4,undefined4 param_5,
            undefined4 *param_6)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar3 = 0x10;
  pcVar5 = "";
  do {
    pcVar4 = param_2;
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    pcVar4 = param_2 + 1;
    cVar2 = *pcVar5;
    cVar1 = *param_2;
    param_2 = pcVar4;
    pcVar5 = pcVar6;
  } while (cVar1 == cVar2);
  if (pcVar4[-1] != pcVar6[-1]) {
    return 0x80020001;
  }
  *param_6 = 0xffffffff;
  if (param_4 == 0) {
    return 0x80020006;
  }
  iVar3 = lstrcmpiA((LPCSTR)*param_3,s_Initialize_00478bb0);
  if (iVar3 == 0) {
    *param_6 = 1;
    return 0;
  }
  iVar3 = lstrcmpiA((LPCSTR)*param_3,&DAT_00478bbc);
  if (iVar3 != 0) {
    return 0x80020006;
  }
  *param_6 = 2;
  return 0;
}


