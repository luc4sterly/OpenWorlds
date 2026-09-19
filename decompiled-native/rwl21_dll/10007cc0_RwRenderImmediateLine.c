// 10007cc0 RwRenderImmediateLine [Global]
// programa: RWL21.DLL

void RwRenderImmediateLine(int *param_1)

{
  byte bVar1;
  code *pcVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  code *pcVar7;
  
                    /* 0x7cc0  347  RwRenderImmediateLine */
  puVar3 = PTR_DAT_1005b69c;
  piVar6 = (int *)(PTR_DAT_1005b69c + 0x2f0);
  if (param_1[0x59] == 0) {
    iVar4 = RwCurrentMaterial();
    param_1[0x59] = iVar4;
  }
  bVar1 = *(byte *)(param_1[0x59] + 0x30);
  *(byte *)(param_1[0x59] + 0x30) = bVar1 | 0x80;
  iVar4 = *param_1;
  if (iVar4 != 0) {
    if (iVar4 != 1) {
      if (iVar4 != 2) goto LAB_10007f31;
      iVar4 = *(int *)(*(int *)(puVar3 + 0x33c) + 0x88) + 0xc;
      param_1[0x68] = iVar4 + param_1[0x1d] * 0x74 + 0x32c;
      param_1[0x69] = iVar4 + param_1[0x3a] * 0x74 + 0x32c;
      if ((*(int *)(puVar3 + 0x348) == 0) || (param_1[1] == 0)) {
        uVar5 = *(uint *)param_1[0x59] & 1;
        if ((int)*(uint *)param_1[0x59] < 4) goto LAB_10007f08;
        pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x74);
      }
      else {
        uVar5 = (*(uint *)param_1[0x59] & 1) + 0x40;
        if ((int)*(uint *)param_1[0x59] < 4) {
LAB_10007f08:
          pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x54);
        }
        else {
          pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x74);
        }
      }
      if (*piVar6 == 0) {
        (*pcVar7)(param_1 + 0x59,0);
      }
      else {
        pcVar2 = *(code **)(puVar3 + 0x2f4);
        FUN_100274c0(pcVar7);
        (*pcVar2)(param_1 + 0x59);
      }
      goto LAB_10007f31;
    }
    if ((*(int *)(puVar3 + 0x348) == 0) || (param_1[1] == 0)) {
      uVar5 = *(uint *)param_1[0x59] & 1;
      if ((int)*(uint *)param_1[0x59] < 4) goto LAB_10007e3e;
      pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x74);
    }
    else {
      uVar5 = (*(uint *)param_1[0x59] & 1) + 0x40;
      if ((int)*(uint *)param_1[0x59] < 4) {
LAB_10007e3e:
        pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x54);
      }
      else {
        pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x74);
      }
    }
    param_1[0x68] = (int)(param_1 + 2);
    param_1[0x69] = (int)(param_1 + 0x1f);
    *(undefined1 *)(param_1[0x68] + 0x48) = 0;
    *(undefined1 *)(param_1[0x69] + 0x48) = 0;
    (*pcVar7)(param_1 + 0x59,0);
    goto LAB_10007f31;
  }
  param_1[0x68] = (int)(param_1 + 2);
  param_1[0x69] = (int)(param_1 + 0x1f);
  if ((*(int *)(puVar3 + 0x348) == 0) || (param_1[1] == 0)) {
    uVar5 = *(uint *)param_1[0x59] & 1;
    if ((int)*(uint *)param_1[0x59] < 4) goto LAB_10007d7a;
    pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x74);
  }
  else {
    uVar5 = (*(uint *)param_1[0x59] & 1) + 0x40;
    if ((int)*(uint *)param_1[0x59] < 4) {
LAB_10007d7a:
      pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x54);
    }
    else {
      pcVar7 = *(code **)(PTR_DAT_1005b69c + uVar5 * 4 + 0x74);
    }
  }
  if (*piVar6 == 0) {
    (**(code **)(PTR_DAT_1005b69c + 0x294))
              (param_1 + 2,2,*(undefined4 *)(puVar3 + 0x340),
               *(undefined4 *)(PTR_DAT_1005b69c + 0x10),1);
    (*pcVar7)(param_1 + 0x59,0);
  }
  else {
    FUN_100274c0(pcVar7);
    pcVar7 = (code *)0x2;
    (**(code **)(PTR_DAT_1005b69c + 0x294))
              (param_1 + 2,2,*(undefined4 *)(puVar3 + 0x340),
               *(undefined4 *)(PTR_DAT_1005b69c + 0x10));
    (*pcVar7)(param_1 + 0x59);
  }
LAB_10007f31:
  *(byte *)(param_1[0x59] + 0x30) = bVar1;
  return;
}


