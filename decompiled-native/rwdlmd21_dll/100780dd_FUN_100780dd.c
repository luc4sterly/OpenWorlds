// 100780dd FUN_100780dd [Global]
// programa: rwdlmd21.dll

void __fastcall FUN_100780dd(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_EAX;
  uint uVar4;
  int unaff_ESI;
  int unaff_EDI;
  uint uVar5;
  
  uVar5 = unaff_EDI + in_EAX * 2 & 6;
  *(undefined8 *)((uint)(&DAT_1008f278 + param_1 * 2 + uVar5) & 0xfffffff8) = 0;
  *(undefined8 *)(uVar5 + 0x1008f276 & 0xfffffff8) = 0;
  iVar3 = DAT_1008d2c8;
  uVar4 = DAT_1008d2c0 & 0x7fff7fff;
  uVar1 = DAT_1008d2c0;
  do {
    uVar2 = uVar4 >> 8;
    uVar4 = uVar4 + iVar3 & 0x7fff7fff;
    *(undefined2 *)(&DAT_1008f278 + param_1 * 2 + uVar5) =
         *(undefined2 *)
          (unaff_ESI +
          CONCAT31((uint3)((uVar1 & 0x7f000000) >> 0x19),
                   (byte)((uVar1 & 0x7f000000) >> 0x11) | (byte)uVar2) * 2);
    param_1 = param_1 + 1;
    uVar1 = uVar4;
  } while (param_1 != 0);
  return;
}


