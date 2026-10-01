// 0042965d FUN_0042965d [Global]
// program: sfmain.exe

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0042965d(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined1 local_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uVar1 = *in_EAX;
  uStack_21 = (undefined1)((uint)uVar1 >> 0x18);
  *(undefined1 *)in_EAX = uStack_21;
  uStack_22 = (undefined1)((uint)uVar1 >> 0x10);
  *(undefined1 *)((int)in_EAX + 1) = uStack_22;
  uStack_23 = (undefined1)((uint)uVar1 >> 8);
  *(undefined1 *)((int)in_EAX + 2) = uStack_23;
  local_24 = (undefined1)uVar1;
  *(undefined1 *)((int)in_EAX + 3) = local_24;
  return;
}


