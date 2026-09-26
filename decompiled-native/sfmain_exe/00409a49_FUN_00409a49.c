// 00409a49 FUN_00409a49 [Global]
// programa: sfmain.exe

void __fastcall FUN_00409a49(int param_1,int param_2)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *unaff_EBX;
  
  iVar2 = *(int *)(param_1 + 0x10) + 1;
  if (iVar2 < 0xb6) {
    iVar2 = 0xb5;
  }
  iVar7 = param_2 + -1;
  for (iVar3 = iVar7 * 4 + in_EAX; (0 < iVar7 && (0x21c < *(int *)(iVar3 + -4))); iVar3 = iVar3 + -4
      ) {
    iVar7 = iVar7 + -1;
  }
  iVar3 = iVar7 + 1;
  if ((iVar3 < 2) || (*(int *)(iVar3 * 4 + in_EAX + -8) < iVar2)) {
    iVar2 = *(int *)(param_1 + 0x10) + 1;
    if (iVar2 < 0x134) {
      iVar2 = 0x133;
    }
    *(int *)(param_1 + 8) = iVar2;
    *(int *)(param_1 + 0x14) = iVar2 + 0x9b;
    *unaff_EBX = 0;
  }
  else {
    iVar4 = iVar7;
    for (iVar5 = iVar7 * 4 + in_EAX; (0 < iVar4 && (iVar2 <= *(int *)(iVar5 + -4)));
        iVar5 = iVar5 + -4) {
      iVar4 = iVar4 + -1;
    }
    iVar5 = iVar4 + 2;
    iVar4 = iVar4 + 1;
    bVar1 = false;
    iVar6 = iVar5 * 4 + in_EAX;
    for (; iVar5 <= iVar7; iVar5 = iVar5 + 1) {
      if (0x59 < *(int *)(iVar6 + -4) - *(int *)(iVar4 * 4 + in_EAX + -4)) {
        bVar1 = true;
        break;
      }
      iVar6 = iVar6 + 4;
    }
    if (!bVar1) {
      iVar7 = iVar2 + 0x59;
      if (iVar7 < 0x168) {
        iVar7 = 0x168;
      }
      iVar6 = iVar4 * 4 + in_EAX;
      iVar5 = *(int *)(iVar6 + -4);
      if (iVar7 < iVar5) {
        *(int *)(param_1 + 0x14) = iVar5 + -1;
        if (iVar2 <= *(int *)(iVar6 + -4) + -0x9c) {
          iVar2 = *(int *)(param_1 + 0x14) + -0x9b;
        }
        *(int *)(param_1 + 8) = iVar2;
        *unaff_EBX = 2;
        return;
      }
    }
    piVar8 = (int *)(iVar4 * 4 + in_EAX);
    *(int *)(param_1 + 8) = piVar8[-1];
    do {
      iVar4 = iVar4 + 1;
      if (iVar3 <= iVar4) {
        iVar2 = *(int *)(param_1 + 8) + 0x9b;
        if (0x21b < iVar2) {
          iVar2 = 0x21c;
        }
LAB_00409c07:
        *(int *)(param_1 + 0x14) = iVar2;
        *unaff_EBX = 1;
        return;
      }
      iVar2 = *piVar8;
      if (*(int *)(param_1 + 8) + 0x9c < iVar2) {
        iVar2 = *(int *)(param_1 + 8) + 0x9b;
        if (0x21b < iVar2) {
          iVar2 = 0x21c;
        }
        goto LAB_00409c07;
      }
      piVar8 = piVar8 + 1;
    } while (iVar2 < *(int *)(param_1 + 8) + 0x5a);
    *(int *)(param_1 + 0x14) = iVar2 + -1;
    *unaff_EBX = 3;
  }
  return;
}


