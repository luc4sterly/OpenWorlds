// 0042b942 FUN_0042b942 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042b942(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)FUN_0042b938();
  uVar2 = 0;
  if (puVar1 != (uint *)0x0) {
    uVar2 = *puVar1 * 0x41c64e6d + 0x3039;
    *puVar1 = uVar2;
    uVar2 = uVar2 >> 0x10 & 0x7fff;
  }
  return CONCAT44(param_2,uVar2);
}


