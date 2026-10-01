// 00402998 FUN_00402998 [Global]
// program: gdkup.exe

/* WARNING: Instruction at (ram,0x00402a1e) overlaps instruction at (ram,0x00402a1c)
    */

undefined8 __fastcall FUN_00402998(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte *in_EAX;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  ushort in_DS;
  bool bVar10;
  bool bVar11;
  
  pbVar6 = in_EAX;
  pbVar5 = param_2;
  if (*param_2 != 0) {
    if (param_2[1] == 0) {
      bVar1 = *param_2;
      pbVar5 = (byte *)CONCAT31((int3)((uint)param_2 >> 8),bVar1);
      do {
        pbVar6 = in_EAX;
        if (*in_EAX == bVar1) goto LAB_00402a4d;
        if (*in_EAX == 0) break;
        pbVar6 = in_EAX + 1;
        if (*pbVar6 == bVar1) goto LAB_00402a4d;
        in_EAX = in_EAX + 2;
      } while (*pbVar6 != 0);
      pbVar6 = (byte *)0x0;
    }
    else {
      pbVar3 = (byte *)0xffffffff;
      bVar10 = true;
      pbVar5 = (byte *)(uint)in_DS;
      do {
        pbVar8 = pbVar6;
        if (pbVar3 == (byte *)0x0) break;
        pbVar3 = pbVar3 + -1;
        pbVar8 = pbVar6 + 1;
        bVar10 = *pbVar6 == 0;
        pbVar6 = pbVar8;
      } while (!bVar10);
      if (!bVar10) {
        pbVar8 = pbVar3;
      }
      uVar4 = 0xffffffff;
      pbVar6 = param_2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        bVar1 = *pbVar6;
        pbVar6 = pbVar6 + 1;
      } while (bVar1 != 0);
      pbVar3 = (byte *)(~uVar4 - 1);
      do {
        pbVar6 = pbVar8 + (-1 - (int)in_EAX);
        bVar10 = pbVar6 == pbVar3;
        if (pbVar6 < pbVar3) {
LAB_00402a4b:
          pbVar6 = (byte *)0x0;
          break;
        }
        if (pbVar6 == (byte *)0x0) {
LAB_00402a1c_2:
          in_EAX = pbVar6;
        }
        else {
          do {
            pbVar5 = in_EAX;
            if (pbVar6 == (byte *)0x0) break;
            pbVar6 = pbVar6 + -1;
            pbVar5 = in_EAX + 1;
            bVar10 = *param_2 == *in_EAX;
            in_EAX = pbVar5;
          } while (!bVar10);
          in_EAX = pbVar5;
          if (!bVar10) goto LAB_00402a1c_2;
        }
        pbVar5 = in_EAX + -1;
        if (pbVar5 == (byte *)0x0) goto LAB_00402a4b;
        bVar10 = false;
        iVar2 = 0;
        bVar11 = true;
        pbVar6 = pbVar3;
        pbVar7 = pbVar5;
        pbVar9 = param_2;
        do {
          if (pbVar6 == (byte *)0x0) break;
          pbVar6 = pbVar6 + -1;
          bVar10 = *pbVar7 < *pbVar9;
          bVar11 = *pbVar7 == *pbVar9;
          pbVar7 = pbVar7 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (!bVar11) {
          iVar2 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
        }
        pbVar6 = pbVar5;
      } while (iVar2 != 0);
    }
  }
LAB_00402a4d:
  return CONCAT44(pbVar5,pbVar6);
}


