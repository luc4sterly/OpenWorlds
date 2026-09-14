// 00446430 FUN_00446430 [Global]
// programa: gamma.dll

undefined4 FUN_00446430(int *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
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
    *param_3 = 0;
    return 0x80004002;
  }
  FUN_00446530(param_1,param_3);
  return 0;
}


