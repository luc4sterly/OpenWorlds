// 10078140 FUN_10078140 [Global]
// programa: rwdlmd21.dll

void __fastcall FUN_10078140(int param_1)

{
  int iVar1;
  short sVar2;
  int in_EAX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  int unaff_EDI;
  uint uVar8;
  
  uVar8 = unaff_EDI + in_EAX * 2 & 6;
  iVar1 = DAT_1008d29c + in_EAX * 2;
  *(undefined8 *)((uint)(&DAT_1008f278 + param_1 * 2 + uVar8) & 0xfffffff8) = 0;
  *(undefined8 *)(uVar8 + 0x1008f276 & 0xfffffff8) = 0;
  uVar4 = DAT_1008d2c0 & 0x7fff7fff;
  uVar3 = DAT_1008d2c0 & 0x7f000000;
  iVar6 = DAT_1008d2e4;
  do {
    while( true ) {
      uVar7 = (ushort)((uint)iVar6 >> 0x10);
      if (*(ushort *)(iVar1 + param_1 * 2) <= uVar7) break;
      uVar3 = uVar4 + DAT_1008d2c8;
      iVar6 = iVar6 + DAT_1008d2ec;
      uVar4 = uVar3 & 0x7fff7fff;
      *(undefined2 *)(&DAT_1008f278 + param_1 * 2 + uVar8) = 0;
      uVar3 = uVar3 & 0x7f000000;
      param_1 = param_1 + 1;
      if (param_1 == 0) {
        return;
      }
    }
    uVar5 = uVar4 + DAT_1008d2c8;
    sVar2 = *(short *)(DAT_1008d2b0 +
                      CONCAT31((uint3)(uVar3 >> 0x19),(byte)(uVar3 >> 0x11) | (byte)(uVar4 >> 8)) *
                      2);
    uVar4 = uVar5 & 0x7fff7fff;
    *(short *)(&DAT_1008f278 + param_1 * 2 + uVar8) = sVar2;
    uVar3 = uVar5 & 0x7f000000;
    if (sVar2 != 0) {
      *(ushort *)(iVar1 + param_1 * 2) = uVar7;
    }
    iVar6 = iVar6 + DAT_1008d2ec;
    param_1 = param_1 + 1;
  } while (param_1 != 0);
  return;
}


