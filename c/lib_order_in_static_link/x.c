int imported(int);

static int internal(int x) {
	return x * 2;
}

int exported(int x) {
	return imported(x) * internal(x);
}
