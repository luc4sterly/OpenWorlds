// 10045440 swap [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _swap
   
   Library: Visual Studio 1998 Release */

void __cdecl swap(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  
  if (param_2 != param_1) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      uVar1 = *param_1;
      *param_1 = *param_2;
      param_1 = param_1 + 1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    }
  }
  return;
}


