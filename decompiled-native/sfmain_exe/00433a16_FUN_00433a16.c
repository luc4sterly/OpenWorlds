// 00433a16 FUN_00433a16 [Global]
// programa: sfmain.exe

void __fastcall FUN_00433a16(undefined4 param_1,uint *param_2)

{
  uint *in_EAX;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  uVar3 = *in_EAX;
  uVar1 = in_EAX[1];
  uVar5 = uVar1 ^ uVar1 & 0xfff00000 ^ 0x100000;
  iVar6 = (uVar1 >> 0x14) - 0x433;
  if (iVar6 != 0) {
    if (uVar1 >> 0x14 < 0x433) {
      iVar7 = 0;
      uVar1 = 0;
      do {
        uVar4 = uVar3;
        uVar3 = uVar5 & 1;
        uVar5 = uVar5 >> 1;
        uVar3 = (uint)(CONCAT14(uVar3 != 0,uVar4) >> 1);
        uVar2 = (uint)(CONCAT14((uVar4 & 1) != 0,uVar1) >> 1);
        iVar7 = iVar7 * 2 + (uint)((uVar1 & 1) != 0);
        iVar6 = iVar6 + 1;
        uVar1 = uVar2;
      } while (iVar6 != 0);
      if ((0x7fffffff < uVar2) && (((uVar2 != 0x80000000 || (iVar7 != 0)) || ((uVar4 & 2) != 0)))) {
        bVar8 = 0xfffffffe < uVar3;
        uVar3 = uVar3 + 1;
        uVar5 = uVar5 + bVar8;
      }
    }
    else {
      do {
        bVar8 = (int)uVar3 < 0;
        uVar3 = uVar3 << 1;
        uVar5 = uVar5 << 1 | (uint)bVar8;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  *param_2 = uVar3;
  param_2[1] = uVar5;
  return;
}


