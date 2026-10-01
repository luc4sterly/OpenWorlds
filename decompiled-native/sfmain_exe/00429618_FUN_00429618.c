// 00429618 FUN_00429618 [Global]
// program: sfmain.exe

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_00429618(void)

{
  undefined2 uVar1;
  undefined2 *in_EAX;
  undefined1 local_1c;
  undefined1 uStack_1b;
  
  uVar1 = *in_EAX;
  uStack_1b = (undefined1)((ushort)uVar1 >> 8);
  *(undefined1 *)in_EAX = uStack_1b;
  local_1c = (undefined1)uVar1;
  *(undefined1 *)((int)in_EAX + 1) = local_1c;
  return;
}


