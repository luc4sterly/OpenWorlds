// 00405e1c FUN_00405e1c [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00405e1c(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int *in_EAX;
  char *pcVar5;
  int iVar6;
  int extraout_ECX;
  uint uVar7;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int *piVar8;
  int iVar9;
  int *piVar10;
  undefined8 uVar11;
  
  iVar2 = *in_EAX;
  iVar6 = in_EAX[3];
  iVar3 = in_EAX[6];
  *(undefined1 *)(iVar6 + 0x1c) = 1;
  iVar9 = iVar2 + *(int *)(iVar3 + 2);
  pbVar4 = *(byte **)(iVar3 + 0xe + in_EAX[8] * 4);
  if (pbVar4 == (byte *)0x0) goto LAB_00405e50;
  piVar8 = (int *)(iVar2 + *(int *)(iVar3 + 6));
  iVar2 = *(int *)(in_EAX[5] + 4);
  bVar1 = *pbVar4;
  piVar10 = (int *)(iVar6 + 0x1e + iVar2);
  if (bVar1 < 9) {
    param_1 = (uint)bVar1 * 4;
    switch(bVar1) {
    case 0:
      pcVar5 = FUN_00405d6b();
      (**(code **)(pcVar5 + 5))();
      param_1 = extraout_ECX_00;
      break;
    case 1:
      if ((*(byte *)(in_EAX + 9) & 1) != 0) {
        *piVar8 = 0;
        break;
      }
      iVar6 = *(int *)(iVar6 + 0x1e) + iVar2;
LAB_00405e6f:
      *piVar8 = iVar6;
      break;
    case 2:
      bVar1 = **(byte **)(pbVar4 + 1);
      if (bVar1 < 3) {
        if (bVar1 != 0) {
          if (bVar1 != 1) break;
          if ((*(byte *)(in_EAX + 9) & 1) == 0) {
            *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0x1e) + iVar2;
          }
          else {
            *(undefined4 *)(iVar6 + 0xc) = 0;
          }
          iVar6 = iVar6 + 0xc;
          goto LAB_00405e6f;
        }
      }
      else if ((3 < bVar1) && (4 < bVar1)) {
        if ((bVar1 < 6) || (8 < bVar1)) break;
        if ((*(byte *)(in_EAX + 9) & 1) != 0) {
          piVar10 = (int *)(iVar6 + 0xc);
          *(undefined4 *)(iVar6 + 0xc) = 0;
        }
      }
      *piVar8 = (int)piVar10;
      break;
    case 4:
      pcVar5 = FUN_00405d6b();
      (**(code **)(pcVar5 + 5))(iVar9);
      param_1 = extraout_ECX_01;
      break;
    case 5:
      goto switchD_00405f53_caseD_5;
    default:
      if ((*(byte *)(in_EAX + 9) & 1) != 0) {
        FUN_00402980(param_1,0);
        param_1 = extraout_ECX;
        break;
      }
    case 3:
      bVar1 = pbVar4[1];
      for (uVar7 = (uint)(bVar1 >> 2); uVar7 != 0; uVar7 = uVar7 - 1) {
        *piVar8 = *piVar10;
        piVar10 = piVar10 + 1;
        piVar8 = piVar8 + 1;
      }
      for (uVar7 = bVar1 & 0xffffff03; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(char *)piVar8 = (char)*piVar10;
        piVar10 = (int *)((int)piVar10 + 1);
        piVar8 = (int *)((int)piVar8 + 1);
      }
      param_1 = 0;
    }
  }
  else {
switchD_00405f53_caseD_5:
    FUN_00405c57();
    param_1 = extraout_ECX_02;
  }
LAB_00405e50:
  uVar11 = FUN_00406bcd(param_1,in_EAX[8] + 1);
  return uVar11;
}


