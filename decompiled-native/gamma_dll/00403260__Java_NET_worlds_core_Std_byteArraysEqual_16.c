// 00403260 _Java_NET_worlds_core_Std_byteArraysEqual@16 [Global]
// programa: gamma.dll

undefined1
_Java_NET_worlds_core_Std_byteArraysEqual_16
          (int *param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  
                    /* 0x3260  150  _Java_NET_worlds_core_Std_byteArraysEqual@16 */
  if ((param_3 == 0) || (param_4 == 0)) {
    uVar3 = (**(code **)(*param_1 + 0x60))(param_1,param_3,param_4);
    return uVar3;
  }
  iVar4 = (**(code **)(*param_1 + 0x2ac))(param_1,param_3);
  iVar5 = (**(code **)(*param_1 + 0x2ac))(param_1,param_4);
  if (iVar4 != iVar5) {
    return 0;
  }
  pcVar6 = (char *)(**(code **)(*param_1 + 0x2e0))(param_1,param_3,0);
  pcVar7 = (char *)(**(code **)(*param_1 + 0x2e0))(param_1,param_4,0);
  pcVar8 = pcVar6;
  pcVar10 = pcVar7;
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    do {
      pcVar9 = pcVar8;
      pcVar11 = pcVar10;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar11 = pcVar10 + 1;
      pcVar9 = pcVar8 + 1;
      cVar2 = *pcVar10;
      cVar1 = *pcVar8;
      pcVar8 = pcVar9;
      pcVar10 = pcVar11;
    } while (cVar1 == cVar2);
    iVar4 = (uint)(byte)pcVar9[-1] - (uint)(byte)pcVar11[-1];
  }
  (**(code **)(*param_1 + 0x300))(param_1,param_3,pcVar6,0);
  (**(code **)(*param_1 + 0x300))(param_1,param_4,pcVar7,0);
  return iVar4 == 0;
}


