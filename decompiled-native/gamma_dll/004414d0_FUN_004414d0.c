// 004414d0 FUN_004414d0 [Global]
// programa: gamma.dll

void __thiscall FUN_004414d0(int param_1,undefined4 param_2,HDC param_3)

{
  HGDIOBJ h;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x14c) = param_2;
  *(HDC *)(*(int *)(param_1 + 0x20) + 0x150) = param_3;
  h = *(HGDIOBJ *)(*(int *)(param_1 + 0x20) + 0x140);
  if (h == (HGDIOBJ)0x0) {
    return;
  }
  SelectObject(param_3,h);
  GdiFlush();
  return;
}


