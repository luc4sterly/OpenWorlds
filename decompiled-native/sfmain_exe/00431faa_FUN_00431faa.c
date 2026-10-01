// 00431faa FUN_00431faa [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_00431faa(undefined4 param_1,undefined4 param_2)

{
  LPVOID pvVar1;
  LPVOID in_EAX;
  BOOL BVar2;
  undefined4 uVar3;
  
  pvVar1 = *(LPVOID *)((int)in_EAX + 8);
  BVar2 = VirtualFree(in_EAX,0,0x8000);
  if (BVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    if ((in_EAX == DAT_0043e528) && (DAT_0043e528 = pvVar1, pvVar1 == (LPVOID)0x0)) {
      DAT_0043e528 = DAT_0043e524;
      DAT_0043e52c = 0;
    }
    if (in_EAX == _DAT_004e57a4) {
      _DAT_004e57a4 = (LPVOID)0x0;
    }
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}


