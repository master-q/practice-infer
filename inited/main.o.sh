'/home/kiwamu/src/infer/facebook-clang-plugins/clang/install/bin/clang-4.0' "@/home/kiwamu/src/practice-infer/inited/infer-out/clang/clang_command_5a14a9.txt" \
  > main.o.biniou
INFER_ARGS="-g^--clang-biniou-file^main.o.biniou" '/home/kiwamu/src/infer/infer/bin/InferClang' "@/home/kiwamu/src/practice-infer/inited/infer-out/clang/clang_command_facefa.txt"
bdump -x -d "/home/kiwamu/src/infer/infer/bin/../etc/clang_ast.dict" -w '!!DUMMY!!' main.o.biniou \
  > main.o.bdump