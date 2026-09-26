// 1007da2f FUN_1007da2f [Global]
// programa: rwdlmd21.dll

void __fastcall FUN_1007da2f(int param_1)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  short sVar4;
  ushort uVar5;
  uint unaff_EDI;
  uint uVar6;
  
  iVar2 = DAT_1008d2ec;
  uVar6 = unaff_EDI & 6;
  iVar1 = DAT_1008d29c + in_EAX * 2;
  iVar3 = DAT_1008d2e4 + DAT_1008d2e8;
  sVar4 = *(short *)(&DAT_1008f278 + param_1 * 2 + uVar6);
  DAT_1008d2e4 = iVar3;
LAB_1007da64:
  do {
    if (sVar4 != 0) {
      uVar5 = (ushort)((uint)iVar3 >> 0x10);
      if (*(ushort *)(iVar1 + param_1 * 2) <= uVar5) {
        *(ushort *)(iVar1 + param_1 * 2) = uVar5;
        iVar3 = iVar3 + iVar2;
        param_1 = param_1 + 1;
        sVar4 = *(short *)(&DAT_1008f278 + param_1 * 2 + uVar6);
        if (param_1 == 0) {
          return;
        }
        goto LAB_1007da64;
      }
      *(undefined2 *)(&DAT_1008f278 + param_1 * 2 + uVar6) = 0;
    }
    iVar3 = iVar3 + iVar2;
    param_1 = param_1 + 1;
    sVar4 = *(short *)(&DAT_1008f278 + param_1 * 2 + uVar6);
    if (param_1 == 0) {
      return;
    }
  } while( true );
}


