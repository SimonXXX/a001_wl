pipeline {
    agent any
	stages {
        stage('Build') {
            steps {
                sh 'echo "this is the build"'
            }
        }

        stage('Test') {
            steps {
                sh 'chmod 700 x64/Release/6771Assignment1.exe'
                sh 'x64/Release/6771Assignment1.exe'
            }
        }
	}
}