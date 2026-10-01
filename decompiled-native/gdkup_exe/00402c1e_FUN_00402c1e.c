// 00402c1e FUN_00402c1e [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_00402c1e(undefined4 param_1,undefined4 param_2)

{
  byte in_AL;
  byte bVar1;
  uint uVar2;
  
  if ((0x2f < in_AL) && (in_AL < 0x3a)) {
    return CONCAT44(param_2,in_AL - 0x30);
  }
  bVar1 = FUN_0040387b();
  if (((bVar1 < 0x61) || (0x69 < bVar1)) && ((bVar1 < 0x6a || (0x72 < bVar1)))) {
    uVar2 = (uint)bVar1;
    if ((0x72 < uVar2) && (uVar2 < 0x7b)) {
      return CONCAT44(param_2,uVar2 - 0x57);
    }
    return CONCAT44(param_2,0x25);
  }
  return CONCAT44(param_2,bVar1 - 0x57);
}


