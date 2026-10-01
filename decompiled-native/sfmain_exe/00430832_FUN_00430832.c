// 00430832 FUN_00430832 [Global]
// program: sfmain.exe

ulonglong __fastcall FUN_00430832(ushort *param_1,int *param_2)

{
  byte bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  bool bVar5;
  ushort *in_EAX;
  uint uVar6;
  int iVar7;
  undefined1 *extraout_ECX;
  undefined1 *puVar8;
  ushort *extraout_ECX_00;
  undefined1 *extraout_ECX_01;
  undefined1 *extraout_ECX_02;
  ushort *extraout_ECX_03;
  undefined1 *extraout_ECX_04;
  undefined1 *extraout_ECX_05;
  ushort *extraout_ECX_06;
  undefined4 extraout_ECX_07;
  short extraout_DX;
  int unaff_EBX;
  uint unaff_EBP;
  ushort *puVar9;
  short in_DS;
  bool bVar10;
  
  bVar5 = true;
  bVar1 = *(byte *)(unaff_EBX + 0x15);
  *(undefined4 *)(unaff_EBX + 0xc) = 0;
  if (bVar1 < 0x69) {
    if (0x57 < bVar1) {
      if (bVar1 < 0x59) goto LAB_00430889;
      if (bVar1 == 100) goto LAB_004308cc;
    }
  }
  else {
    if (0x69 < bVar1) {
      if (bVar1 < 0x75) {
        bVar10 = bVar1 == 0x6f;
      }
      else {
        if (bVar1 < 0x76) goto LAB_00430889;
        bVar10 = bVar1 == 0x78;
      }
      if (!bVar10) goto LAB_004308d6;
LAB_00430889:
      if ((*(byte *)(unaff_EBX + 0x14) & 0x20) == 0) {
        if ((*(byte *)(unaff_EBX + 0x14) & 0x10) == 0) {
          puVar2 = (uint *)*param_2;
          *param_2 = (int)(puVar2 + 1);
          unaff_EBP = *puVar2;
        }
        else {
          puVar9 = (ushort *)*param_2;
          *param_2 = (int)(puVar9 + 2);
          unaff_EBP = (uint)*puVar9;
        }
      }
      else {
        puVar2 = (uint *)*param_2;
        *param_2 = (int)(puVar2 + 1);
        unaff_EBP = *puVar2;
      }
      *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
    }
LAB_004308cc:
    if (*(int *)(unaff_EBX + 8) != -1) {
      *(undefined1 *)(unaff_EBX + 0x16) = 0x20;
    }
  }
LAB_004308d6:
  bVar1 = *(byte *)(unaff_EBX + 0x15);
  if (bVar1 < 0x65) {
    if (bVar1 < 0x50) {
      if (bVar1 < 0x46) {
        bVar10 = bVar1 == 0x45;
      }
      else {
        if (bVar1 < 0x47) goto LAB_00430991;
        bVar10 = bVar1 == 0x47;
      }
      if (!bVar10) goto LAB_00430c40;
      goto LAB_004309c3;
    }
    if (0x50 < bVar1) {
      if (bVar1 < 0x58) {
        if (bVar1 != 0x53) goto LAB_00430c40;
LAB_00430a6e:
        if ((*(byte *)(unaff_EBX + 0x14) & 0x80) == 0) {
          if ((*(byte *)(unaff_EBX + 0x14) & 0x40) == 0) {
            puVar3 = (undefined4 *)*param_2;
            *param_2 = (int)(puVar3 + 1);
            puVar9 = (ushort *)*puVar3;
          }
          else {
            puVar3 = (undefined4 *)*param_2;
            *param_2 = (int)(puVar3 + 1);
            puVar9 = (ushort *)*puVar3;
          }
          if (puVar9 != (ushort *)0x0) {
            param_1 = puVar9;
          }
        }
        else {
          puVar3 = (undefined4 *)*param_2;
          *param_2 = (int)(puVar3 + 2);
          if (((ushort *)*puVar3 != (ushort *)0x0) || (*(short *)(puVar3 + 1) != 0)) {
            param_1 = (ushort *)*puVar3;
            in_DS = *(short *)(puVar3 + 1);
          }
        }
        bVar1 = *(byte *)(unaff_EBX + 0x14);
        bVar5 = false;
        *(byte *)(unaff_EBX + 0x14) = bVar1 & 0xf9;
        if (*(char *)(unaff_EBX + 0x15) == 'S') {
          if ((bVar1 & 0x20) == 0) {
            uVar6 = (uint)(byte)*param_1;
            in_EAX = (ushort *)((int)param_1 + 1);
          }
          else {
            uVar6 = (uint)*param_1;
            in_EAX = param_1 + 1;
          }
        }
        else {
          if ((bVar1 & 0x20) == 0) goto LAB_00430a13;
          uVar6 = FUN_004306b5();
          in_EAX = extraout_ECX_03;
        }
      }
      else {
        if (bVar1 < 0x59) {
LAB_00430b37:
          if (((*(byte *)(unaff_EBX + 0x14) & 1) != 0) && (unaff_EBP != 0)) {
            *(undefined1 *)(unaff_EBX + 0x17) = 0x30;
            *(undefined1 *)(unaff_EBX + 0x19) = 0;
            *(undefined1 *)(unaff_EBX + 0x18) = *(undefined1 *)(unaff_EBX + 0x15);
          }
LAB_00430b5a:
          FUN_0042cf3e(in_EAX,(char *)in_EAX);
          puVar8 = extraout_ECX_04;
          if (*(char *)(unaff_EBX + 0x15) == 'X') {
            FUN_00430d1b();
            puVar8 = extraout_ECX_05;
          }
          goto LAB_004309f7;
        }
        if (bVar1 < 99) goto LAB_00430c40;
        if (99 < bVar1) goto LAB_00430a1d;
        pbVar4 = (byte *)*param_2;
        *param_2 = (int)(pbVar4 + 4);
        bVar1 = *pbVar4;
        *(byte *)((int)in_EAX + 1) = 0;
        *(byte *)in_EAX = bVar1;
        *(undefined4 *)(unaff_EBX + 8) = 1;
        bVar5 = false;
        uVar6 = 1;
        *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
      }
      goto LAB_00430c69;
    }
LAB_00430b7d:
    if (*(int *)(unaff_EBX + 4) == 0) {
      if ((*(byte *)(unaff_EBX + 0x14) & 0x80) == 0) {
        *(undefined4 *)(unaff_EBX + 4) = 8;
      }
      else {
        *(undefined4 *)(unaff_EBX + 4) = 0xd;
      }
    }
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
    iVar7 = *param_2;
    *param_2 = iVar7 + 4;
    puVar9 = in_EAX;
    if ((*(byte *)(unaff_EBX + 0x14) & 0x80) != 0) {
      *param_2 = iVar7 + 8;
      FUN_004306d8(in_EAX,(char *)in_EAX);
      puVar9 = (ushort *)((int)in_EAX + 5);
      *(byte *)(in_EAX + 2) = 0x3a;
      in_EAX = extraout_ECX_06;
    }
    FUN_004306d8(in_EAX,(char *)puVar9);
    if (*(char *)(unaff_EBX + 0x15) == 'P') {
      FUN_00430d1b();
    }
LAB_00430a13:
    uVar6 = FUN_00430691();
    in_EAX = extraout_ECX_00;
  }
  else {
    if (bVar1 < 0x66) {
LAB_004309c3:
      FUN_0043082b();
      in_DS = extraout_DX;
      goto LAB_00430a13;
    }
    if (bVar1 < 0x6f) {
      if (bVar1 < 0x67) {
LAB_00430991:
        if ((*(byte *)(unaff_EBX + 0x14) & 0x10) != 0) {
          puVar2 = (uint *)*param_2;
          *param_2 = (int)(puVar2 + 1);
          FUN_00430736(in_EAX,*puVar2);
          goto LAB_00430a13;
        }
      }
      else if (0x67 < bVar1) {
        if (bVar1 == 0x69) {
LAB_00430a1d:
          if ((*(byte *)(unaff_EBX + 0x14) & 0x20) == 0) {
            if ((*(byte *)(unaff_EBX + 0x14) & 0x10) == 0) {
              *param_2 = *param_2 + 4;
              FUN_004323f4(in_EAX,(char *)in_EAX);
              puVar8 = extraout_ECX_02;
              goto LAB_004309f7;
            }
            *param_2 = *param_2 + 4;
          }
          else {
            *param_2 = *param_2 + 4;
          }
          FUN_0042cf88(in_EAX,(char *)in_EAX);
          puVar8 = extraout_ECX_01;
          goto LAB_004309f7;
        }
        goto LAB_00430c40;
      }
      goto LAB_004309c3;
    }
    if (bVar1 < 0x70) {
      puVar9 = in_EAX;
      if ((*(byte *)(unaff_EBX + 0x14) & 1) != 0) {
        *(byte *)in_EAX = 0x30;
        puVar9 = (ushort *)((int)in_EAX + 1);
      }
      FUN_0042cf88(in_EAX,(char *)puVar9);
      puVar8 = extraout_ECX;
      in_EAX = puVar9;
LAB_004309f7:
      if ((*(int *)(unaff_EBX + 8) == 0) && ((byte)*in_EAX == 0x30)) {
        *puVar8 = 0;
      }
      goto LAB_00430a13;
    }
    if (bVar1 < 0x73) {
      if (bVar1 == 0x70) goto LAB_00430b7d;
    }
    else {
      if (bVar1 < 0x74) goto LAB_00430a6e;
      if (0x74 < bVar1) {
        if (bVar1 < 0x76) goto LAB_00430b5a;
        if (bVar1 == 0x78) goto LAB_00430b37;
      }
    }
LAB_00430c40:
    *(undefined4 *)(unaff_EBX + 4) = 0;
    bVar1 = *(byte *)(unaff_EBX + 0x15);
    *(byte *)((int)in_EAX + 1) = 0;
    *(byte *)in_EAX = bVar1;
    *(undefined4 *)(unaff_EBX + 8) = 1;
    bVar5 = false;
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
    uVar6 = 1;
  }
LAB_00430c69:
  if (!bVar5) goto LAB_00430cbe;
  if ((byte)*in_EAX == 0x2d) {
    *(undefined1 *)(unaff_EBX + 0x17) = 0x2d;
    uVar6 = uVar6 - 1;
LAB_00430ca7:
    *(undefined1 *)(unaff_EBX + 0x18) = 0;
  }
  else {
    if ((*(byte *)(unaff_EBX + 0x14) & 2) != 0) {
      *(undefined1 *)(unaff_EBX + 0x17) = 0x20;
      goto LAB_00430ca7;
    }
    if ((*(byte *)(unaff_EBX + 0x14) & 4) != 0) {
      *(undefined1 *)(unaff_EBX + 0x17) = 0x2b;
      goto LAB_00430ca7;
    }
  }
  if (*(int *)(unaff_EBX + 8) < (int)uVar6) {
    *(uint *)(unaff_EBX + 8) = uVar6;
  }
  else {
    *(uint *)(unaff_EBX + 0xc) = *(int *)(unaff_EBX + 8) - uVar6;
  }
LAB_00430cbe:
  if (*(char *)(unaff_EBX + 0x16) == '*') {
    *(undefined1 *)(unaff_EBX + 0x17) = 0;
    *(byte *)(unaff_EBX + 0x14) = *(byte *)(unaff_EBX + 0x14) & 0xf9;
  }
  if (((*(int *)(unaff_EBX + 8) == -1) || ((int)uVar6 < *(int *)(unaff_EBX + 8))) &&
     (*(char *)(unaff_EBX + 0x15) != 'c')) {
    *(uint *)(unaff_EBX + 8) = uVar6;
  }
  iVar7 = FUN_00430691();
  *(int *)(unaff_EBX + 4) =
       *(int *)(unaff_EBX + 4) - (iVar7 + *(int *)(unaff_EBX + 8) + *(int *)(unaff_EBX + 0xc));
  return (ulonglong)CONCAT24(in_DS,extraout_ECX_07);
}


