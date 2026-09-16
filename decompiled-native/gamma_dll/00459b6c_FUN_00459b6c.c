// 00459b6c FUN_00459b6c [Global]
// programa: gamma.dll

undefined8 __fastcall FUN_00459b6c(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 in_EAX;
  
  uVar1 = (undefined1)((uint)in_EAX >> 8);
  return CONCAT44(CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(uVar1,uVar1)),
                  CONCAT31(CONCAT21((short)((uint)in_EAX >> 0x10),(char)in_EAX),uVar1));
}


