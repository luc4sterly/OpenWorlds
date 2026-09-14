// 00457480 FUN_00457480 [Global]
// programa: gamma.dll

/* WARNING: Unable to track spacebase fully for stack */

undefined8 __fastcall FUN_00457480(undefined4 param_1,undefined4 param_2)

{
  uint in_EAX;
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)&stack0x00000004;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    puVar1 = puVar1 + -0x400;
    *puVar1 = *puVar1;
  }
  puVar1 = (undefined4 *)((int)puVar1 - in_EAX);
  *puVar1 = *puVar1;
  puVar1[-1] = unaff_retaddr;
  return CONCAT44(param_2,puVar1);
}


