clean:
	find . -name '*.bin' -type f -exec rm -f {} + 
	find . -name 'output' -type d -exec rm -rf {} +