// 100453e0 shortsort [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _shortsort
   
   Library: Visual Studio 1998 Release */

void __cdecl shortsort(undefined1 *param_1,undefined1 *param_2,int param_3,undefined *param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  for (; puVar2 = param_1, puVar1 = param_1, param_1 < param_2; param_2 = param_2 + -param_3) {
    while (puVar1 = puVar1 + param_3, puVar1 <= param_2) {
      iVar3 = (*(code *)param_4)(puVar1,puVar2);
      if (0 < iVar3) {
        puVar2 = puVar1;
      }
    }
    swap(puVar2,param_2,param_3);
  }
  return;
}


