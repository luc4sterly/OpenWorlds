// 00441bb0 FUN_00441bb0 [Global]
// program: gamma.dll

undefined4
FUN_00441bb0(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,uint param_5,
            undefined4 *param_6,undefined2 *param_7,undefined4 param_8,undefined4 *param_9)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  iVar7 = 0x10;
  pcVar9 = "";
  do {
    pcVar8 = param_3;
    pcVar10 = pcVar9;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar10 = pcVar9 + 1;
    pcVar8 = param_3 + 1;
    cVar2 = *pcVar9;
    cVar1 = *param_3;
    param_3 = pcVar8;
    pcVar9 = pcVar10;
  } while (cVar1 == cVar2);
  if (pcVar8[-1] != pcVar10[-1]) {
    return 0x80020001;
  }
  switch(param_2) {
  case 1:
    break;
  case 2:
    if ((param_5 & 1) == 0) {
      return 0x80020003;
    }
    if (param_6[2] != 1) {
      return 0x8002000e;
    }
    if (*(short *)*param_6 != 8) {
      *param_9 = 0;
      return 0x80020005;
    }
    uVar3 = *(undefined4 *)((short *)*param_6 + 4);
    piVar4 = (int *)FUN_0040a9d0();
    uVar5 = Ordinal_7(uVar3);
    (**(code **)(*piVar4 + 0x28c))(piVar4,uVar3,uVar5);
    iVar7 = (**(code **)(*piVar4 + 0x18))(piVar4,s_NET_worlds_console_NSProtocolHan_00478b68);
    if (iVar7 != 0) {
      iVar6 = FUN_004031c0(piVar4,iVar7,s_newURL_00478ba8,s__Ljava_lang_String__V_00478b90);
      FUN_00402bd0(piVar4,iVar7,iVar6);
    }
    return 0;
  default:
    return 0;
  }
  if ((param_5 & 1) == 0) {
    return 0x80020003;
  }
  if (param_6[2] != 2) {
    return 0x8002000e;
  }
  if (((short *)*param_6)[8] != 8) {
    *param_9 = 1;
    return 0x80020005;
  }
  if (*(short *)*param_6 != 8) {
    *param_9 = 0;
    return 0x80020005;
  }
  if (param_7 != (undefined2 *)0x0) {
    Ordinal_8(param_7);
    *param_7 = 2;
    param_7[4] = 1;
  }
  return 0;
}


