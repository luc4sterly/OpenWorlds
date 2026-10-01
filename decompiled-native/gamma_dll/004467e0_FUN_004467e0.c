// 004467e0 FUN_004467e0 [Global]
// program: gamma.dll

int FUN_004467e0(int *param_1,undefined4 param_2,char *param_3,undefined4 param_4,undefined4 param_5
                ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  int *piStack_14;
  
  iVar3 = 0x10;
  pcVar4 = "";
  do {
    pcVar5 = pcVar4;
    pcVar6 = param_3;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = param_3 + 1;
    pcVar5 = pcVar4 + 1;
    cVar2 = *param_3;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
    param_3 = pcVar6;
  } while (cVar1 == cVar2);
  if (pcVar5[-1] != pcVar6[-1]) {
    return -0x7ffdffff;
  }
  iVar3 = (**(code **)(*param_1 + 0x10))(param_1,0,param_4,&piStack_14);
  if (-1 < iVar3) {
    iVar3 = (**(code **)(*piStack_14 + 0x2c))
                      (piStack_14,param_1,param_2,param_5,param_6,param_7,param_8,param_9);
    (**(code **)(*piStack_14 + 8))(piStack_14);
    return iVar3;
  }
  return iVar3;
}


