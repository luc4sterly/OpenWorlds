// 00406528 FUN_00406528 [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_00406528(undefined4 param_1,undefined4 param_2)

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
    if ((in_EAX == DAT_00408b2c) && (DAT_00408b2c = pvVar1, pvVar1 == (LPVOID)0x0)) {
      DAT_00408b2c = DAT_00408b28;
      DAT_00408b30 = 0;
    }
    if (in_EAX == DAT_0040b434) {
      DAT_0040b434 = (LPVOID)0x0;
    }
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}


