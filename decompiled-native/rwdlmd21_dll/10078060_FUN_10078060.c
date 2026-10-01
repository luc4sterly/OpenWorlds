// 10078060 FUN_10078060 [Global]
// program: rwdlmd21.dll

void __fastcall FUN_10078060(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  uint uVar3;
  uint uVar4;
  int unaff_EDI;
  uint uVar5;
  
  iVar2 = DAT_1008d2ec;
  uVar4 = DAT_1008d2e4;
  uVar5 = unaff_EDI + in_EAX * 2 & 6;
  iVar1 = DAT_1008d29c + in_EAX * 2;
  *(undefined8 *)(uVar5 + 0x1008f276 & 0xfffffff8) = 0;
  *(undefined8 *)((uint)(&DAT_1008f278 + param_1 * 2 + uVar5) & 0xfffffff8) = 0;
  uVar3 = uVar4 >> 0x10;
  do {
    while (*(ushort *)(iVar1 + param_1 * 2) <= (ushort)uVar3) {
      *(ushort *)(iVar1 + param_1 * 2) = (ushort)uVar3;
      *(undefined2 *)(&DAT_1008f278 + param_1 * 2 + uVar5) = 0xffff;
      uVar4 = uVar4 + iVar2;
      uVar3 = uVar4 >> 0x10;
      param_1 = param_1 + 1;
      if (param_1 == 0) {
        return;
      }
    }
    *(undefined2 *)(&DAT_1008f278 + param_1 * 2 + uVar5) = 0;
    uVar4 = uVar4 + iVar2;
    uVar3 = uVar4 >> 0x10;
    param_1 = param_1 + 1;
  } while (param_1 != 0);
  return;
}


